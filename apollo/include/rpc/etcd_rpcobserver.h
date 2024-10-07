//
// Created by root on 10/5/24.
//

#ifndef APOLLO_ETCD_RPCOBSERVER_H
#define APOLLO_ETCD_RPCOBSERVER_H
#include "rpcobserver.h"
#include "etcd/SyncClient.hpp"
#include "inetaddress.h"
namespace apollo {
class EtcdRpcObserver : public RpcObserver {
public:
    explicit EtcdRpcObserver(const InetAddress& observer_address);
    virtual ~EtcdRpcObserver();

    virtual void start();

    /**
     * @brief 创建服务实例
     *
     * @param path 路径
     * @param data 节点数据
     */
    virtual void createData(const std::string& path, const std::string& data);

    /**
     * @brief 获取服务数据
     *
     * @param path 节点路径
     * @return std::string
     */
    virtual std::string getData(const std::string& path);
    /**
     * @brief 删除服务实例
     *
     * @param path 路径
     * @return bool isDeleteSuccessful
     */
    virtual bool deleteData(const std::string& path);

private:
    etcd::SyncClient etcd_client_;
};
}
#endif // APOLLO_ETCD_RPCOBSERVER_H