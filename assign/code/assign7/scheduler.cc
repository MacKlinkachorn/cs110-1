/**
 * File: scheduler.cc
 * ------------------
 * Presents the implementation of the HTTPProxyScheduler class.
 */

#include "scheduler.h"
#include <utility>
using namespace std;

void HTTPProxyScheduler::scheduleRequest(int clientfd, const string& clientIPAddress) throw () {
  pool.schedule([this, clientfd, clientIPAddress]{
    requestHandler.serviceRequest(make_pair(clientfd, clientIPAddress));
  });
}
