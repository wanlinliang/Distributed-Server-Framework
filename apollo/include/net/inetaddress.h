#ifndef __APOLLO_INET_ADDRESS_H__
#define __APOLLO_INET_ADDRESS_H__

#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>

namespace apollo {
/**
 * @brief 封装socket地址类型
 */
class InetAddress {
public:
    explicit InetAddress(uint16_t port = 0, const std::string& ip = "0.0.0.0");

    explicit InetAddress(const sockaddr_in& addr)
        : addr_(addr) { }

    /**
     * @brief 将IP地址转化为字符串
     * 
     * @return std::string 
     */
    std::string toIp() const;

    /**
     * @brief 将IP地址和端口号转化为字符串形式
     * 
     * @return std::string 
     */
    std::string toIpPort() const;

    /**
     * @brief 获取端口号
     * 
     * @return uint16_t 
     */
    uint16_t toPort() const;

    /**
     * @brief Get the Sock Addr object
     * 
     * @return const sockaddr_in* 
     */
    const sockaddr_in* getSockAddr() const { return &addr_; }

    /**
     * @brief 设置IP地址和端口号
     * 
     * @param addr 
     */
    void setSockAddr(const sockaddr_in& addr) { addr_ = addr; }

private:
    sockaddr_in addr_;
};
} // namespace apollo

#endif // !__APOLLO_INET_ADDRESS_H__
