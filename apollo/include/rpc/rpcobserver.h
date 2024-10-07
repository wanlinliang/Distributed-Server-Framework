//
// Created by root on 10/5/24.
//

#ifndef APOLLO_RPCOBSERVER_H
#define APOLLO_RPCOBSERVER_H
#include <string>
#include "inetaddress.h"
namespace apollo {
class RpcObserver{
public:
    RpcObserver(const InetAddress& observer_address) {};
    RpcObserver(const RpcObserver&) = delete;
    RpcObserver& operator=(const RpcObserver&) = delete;
    virtual ~RpcObserver(){};

     /**
     * @brief 启动客户端
     *
     */
    virtual void start() = 0;
    /**
     * @brief 创建服务实例
     *
     * @param path 路径
     * @param data 节点数据
     */
    virtual void createData(const std::string& path, const std::string& data) = 0;

    /**
     * @brief 获取服务数据
     *
     * @param path 节点路径
     * @return std::string
     */
    virtual std::string getData(const std::string& path) = 0;
    /**
     * @brief 删除服务实例
     *
     * @param path 路径
     * @return bool isDeleteSuccessful
     */
    virtual bool deleteData(const std::string& path) = 0;
};
}


#endif // APOLLO_RPCOBSERVER_H
