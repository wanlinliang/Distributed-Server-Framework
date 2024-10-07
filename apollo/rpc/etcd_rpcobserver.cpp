//
// Created by root on 10/5/24.
//
#include "etcd_rpcobserver.h"
#include "inetaddress.h"
namespace apollo {

EtcdRpcObserver::EtcdRpcObserver(const InetAddress& observer_address)
    : RpcObserver(observer_address), etcd_client_(observer_address.toIpPort()) {
}

EtcdRpcObserver::~EtcdRpcObserver(){}

void EtcdRpcObserver::start() {}

void EtcdRpcObserver::createData(const std::string& path, const std::string& data) {
    etcd_client_.set(path, data);
}

std::string EtcdRpcObserver::getData(const std::string& path) {
    return etcd_client_.get(path).value().as_string();
}

bool EtcdRpcObserver::deleteData(const std::string& path) {
    etcd_client_.rm(path);
    return true; //Fixme
}

} // namespace apollo