// eJyNkc1OwzAQhLWvUnGAS_0q0hUNuNCqI_1qQBN2dkmiW14tqWvWlIn54YqKBcQHta6Zsdzay3KhKlsIQuSTZpzqWuIQbWzwgGUTSkzuJwivPWrbgZ8aL2_1LGNs_1Q4XzK9SrnKN5zZaTUVpqqe42g3OJN1Lnsw4wWb0KL2tKoP6644Zot2drvO2_1s0CzzrDZWkCwY8XyZJIzWNRwAwpL0FbTQyuAZrHPXcT_0Kkmr1Zh95Lo8EZhYEy2xrpKSwMPLoDOkgbT2a_1lH1SoeBVNX73696Z_12VcXEFqtCeh6RNf67zRW2oEBasv7YvpXYTuxeQa_1FY4JNfdCamw5KhL_1xcfOpch5KmG_13cOEtzHx6D_1WSlIgPPkpK6ADAm1aRHJQ4h1MwH2Dj1KJpE




#include "./TweetsExport.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR TweetsExport_Base
#define MY_OPERATOR TweetsExport$OP


#include <SPL/Runtime/Common/ApplicationRuntimeMessage.h>
#include <SPL/Runtime/Utility/LogTraceMessage.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Toolkit/Utility.h>
#include <signal.h>

using namespace std;
using namespace streams_boost::iostreams;


void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady()
{
        createThreads (1);
}


void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown()
{
    AutoMutex am (_mutex);
    if (_fd_sink.get())
        _filt_str.reset();
    _connected = false;
    _numConnections.setValueNoLock(0);
    
        _cv.broadcast();
    
    if (_connector.get())
        _connector->terminate();
}

// we have the mutex, already
void MY_OPERATOR_SCOPE::MY_OPERATOR::cleanup()
{
    
    _fs.reset(NULL);
    _filt_str.reset(NULL);
    _fd_sink.reset(NULL);
    _connected = false;
    _numConnections.setValueNoLock(0);
    
        _cv.broadcast();
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::setup (int32_t fd)
{
    AutoMutex am (_mutex);
    setupLocked(fd);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::setupLocked (int32_t fd)
{
    if (!_connector.get() || !_connector->connected())
        return;
    if (0 != shutdown (fd, SHUT_RD)) { 
        SPLAPPTRC(L_DEBUG, "TCPClient: shutdown socket reads failed: " << RuntimeUtility::getErrorNoStr(), SPL_OPER_DBG);
    }
    _fd_sink.reset (new file_descriptor_sink(fd, never_close_handle));
    _filt_str.reset (new filtering_streambuf<output>);
    
    _filt_str->push (*_fd_sink);
    _fs.reset(new ostream(_filt_str.get()));
    _fs->imbue(locale::classic());
    
    _connected = true;
    _numConnections.setValueNoLock(1);
    
        _cv.broadcast();
    
    SPLAPPTRC(L_DEBUG, "TCPSink: file descriptor: " << fd, SPL_OPER_DBG);
}


void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t) 
{
    SPLAPPTRC(L_DEBUG, "TCPSink Connector startup...", SPL_OPER_DBG);
    _connector.reset(new SPL::TCPServer(getPE()));
    
    
        
        
            _connector->setup(lit$0);
        
    
    if (_connector->connected()) {
        setup (_connector->fileDescriptor());
        SPLAPPTRC(L_DEBUG, "TCPSink connected...", SPL_OPER_DBG);
    }

    
        while (!_connectionClosed && 
                !getPE().getShutdownRequested() ) {
            if (!_connected) {
                {
                    // Check to see if we are already finished working (Final seen)
                    AutoMutex am(_mutex);
                    if (_connectionClosed)
                        break; // We are all done here.
                }
                int fd = _connector->reconnect();
                _numReconnects.incrementValueNoLock();
                
                SPLAPPTRC(L_DEBUG, "TCPSink reconnected...", SPL_OPER_DBG);
                setup (fd);
            } else {
                timespec ts = { 1, 0 };
                AutoMutex am(_mutex);
                if(_connected)
                    _cv.waitFor(_mutex, ts);
            }
        }
    

    SPLAPPTRC(L_DEBUG, "TCPSink Connector exiting...", SPL_OPER_DBG);
}


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
: 
    _connected(false), _connectionClosed(false),
    
    _numReconnects(getContext().getMetrics().getCustomMetricByName("nReconnections")),
    _numConnections(getContext().getMetrics().getCustomMetricByName("nConnections")),
    _numWireFormatHandshakesFailed(getContext().getMetrics().getCustomMetricByName("nConfirmWireFormatFailures"))

{
    SPLAPPTRC(L_DEBUG, "TCPSink startup...", SPL_OPER_DBG);
    
    _tuplesUntilFlush = SPL::uint32(1U);
    signal (SIGPIPE, SIG_IGN);
    _numReconnects.setValueNoLock(0);
    _numConnections.setValueNoLock(0);
    _numWireFormatHandshakesFailed.setValueNoLock(0);
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::closeConnection()
{
    _connectionClosed = true;
    cleanup();
    if (_connector.get())
        _connector->terminate();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) {
    AutoMutex am(_mutex);
    
        if(_connected)         
            processInternal(punct, port);
    
    // Ensure that we close the connection when we see the Final punctuation
    if (punct == Punctuation::FinalMarker)
        closeConnection();
}

bool MY_OPERATOR_SCOPE::MY_OPERATOR::processInternal(Punctuation const & punct, uint32_t port) {
    try {
        
        
        
            if (_fs.get()) {
                if (!_fs->flush()) {
                    SPLTRACEMSG(L_WARN, SPL_APPLICATION_RUNTIME_TCPSINK_LOST_CONNECTION, SPL_OPER_DBG);
                    cleanup();
                    return false;
                }
            }
            _tuplesUntilFlush = SPL::uint32(1U);
        
        if (punct == Punctuation::FinalMarker) {
            SPLAPPTRC(L_DEBUG, "TCPSink received FinalMarker...", SPL_OPER_DBG);
            
            cleanup();
        }
    } catch (const std::exception& e) {
        SPLAPPTRC(L_ERROR, SPL_APPLICATION_RUNTIME_EXCEPTION(e.what()), SPL_OPER_DBG);
        cleanup();
        return false;
    } catch (...) {
        SPLAPPTRC(L_ERROR, SPL_APPLICATION_RUNTIME_UNKNOWN_EXCEPTION, SPL_OPER_DBG);
        cleanup();
        return false;
    }
    return true;
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
    AutoMutex am(_mutex);
    
        
        bool sent = false;
        while (!getPE().getShutdownRequested() && !sent) {
            if(_connected && isDisconnected()) {
                SPLAPPTRC(L_WARN, SPL_APPLICATION_RUNTIME_TCPSINK_LOST_CONNECTION, SPL_OPER_DBG);
                cleanup();
            }
            if(!_connected || !(sent=processInternal(tuple, port))) {
                
                    _cv.wait(_mutex);  
                
            }
        }
    
}

bool MY_OPERATOR_SCOPE::MY_OPERATOR::processInternal(Tuple const & tuple$, uint32_t port)
{
    // Write to output
    const IPort0Type& tuple = static_cast<const IPort0Type&>(tuple$);
    try {
        
        
        	    SPL::serializeWithPrecision((*_fs), tuple.get_data()) << ',';
	    SPL::serializeWithPrecision((*_fs), tuple.get_totalTweets()) << '\n';

        if (_fs->fail()) {
            SPLAPPTRC(L_WARN, SPL_APPLICATION_RUNTIME_TCPSINK_LOST_CONNECTION, SPL_OPER_DBG);
            cleanup();
            return false;
        }
        
        if (--_tuplesUntilFlush == 0) {
            _tuplesUntilFlush = SPL::uint32(1U);
            if (!_fs->flush()) {
                SPLTRACEMSG(L_WARN, SPL_APPLICATION_RUNTIME_TCPSINK_LOST_CONNECTION, SPL_OPER_DBG);
                cleanup();
                return false;
            }
        }
        
    } catch (const std::exception& e) {
        SPLAPPTRC(L_ERROR, SPL_APPLICATION_RUNTIME_EXCEPTION(e.what()), SPL_OPER_DBG);
        cleanup();
        return false;
    } catch (...) {
        SPLAPPTRC(L_ERROR, SPL_APPLICATION_RUNTIME_UNKNOWN_EXCEPTION, SPL_OPER_DBG);
        cleanup();
        return false;
    }
    return true;
}


bool MY_OPERATOR_SCOPE::MY_OPERATOR::isDisconnected()
{
    bool anotherConnectionAvailable;
    bool disconnected = _connector->isDisconnected (anotherConnectionAvailable);
    if (disconnected) {
        SPLTRACEMSG(L_WARN, SPL_APPLICATION_RUNTIME_TCPSINK_LOST_CONNECTION, SPL_OPER_DBG);
        if (anotherConnectionAvailable && canReconnect()) {
            reconnectToNewConnection();
            return false;
        } else
            cleanup();
        return true;
    }
    return false;
}

bool MY_OPERATOR_SCOPE::MY_OPERATOR::canReconnect()
{
    
        return true;
    

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reconnectToNewConnection()
{
    SPLAPPTRC(L_DEBUG, "TCPSink reconnecting to pending connection", SPL_OPER_DBG);
    
    _fs.reset(NULL);
    _filt_str.reset(NULL);
    _fd_sink.reset(NULL);

    int fd = _connector->reconnect();
    _numReconnects.incrementValueNoLock();
    
    SPLAPPTRC(L_DEBUG, "TCPSink reconnected...", SPL_OPER_DBG);
    setupLocked (fd);
}


static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("TweetsExport",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    addParameterValue ("port", SPL::ConstValueHandle(lit$0));
    param$role$0 = "server";
    addParameterValue ("role", SPL::ConstValueHandle(param$role$0));
    param$flush$0 = SPL::uint32(1U);
    addParameterValue ("flush", SPL::ConstValueHandle(param$flush$0));
    param$flushOnPunctuation$0 = true;
    addParameterValue ("flushOnPunctuation", SPL::ConstValueHandle(param$flushOnPunctuation$0));
    param$retryFailedSends$0 = true;
    addParameterValue ("retryFailedSends", SPL::ConstValueHandle(param$retryFailedSends$0));
    (void) getParameters(); // ensure thread safety by initializing here
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::punctPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    {
        punctNoPermitProcessRaw(punct, port);
    }
}

void MY_BASE_OPERATOR::punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    switch(punct) {
    case Punctuation::WindowMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::FinalMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::DrainMarker:
    case Punctuation::ResetMarker:
    case Punctuation::ResumeMarker:
        break;
    case Punctuation::SwitchMarker:
        break;
    default:
        break;
    }
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    switch(port) {
    case 0:
        punctNoPermitProcessRaw(punct, port);
        break;
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return false;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}


