#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/socket.h>

int main(void)
{
  struct ifaddrs *addresses;

  if (getifaddrs(&addresses) == -1)
  {
    printf("getifaddrs call faild\n");
    return -1;
  }

  struct ifaddrs *address = addresses;
  while(address)
  {
    if (address->ifa_addr == NULL)
    {
      address = address->ifa_next;
      continue;
    }
    int ips = address->ifa_addr->sa_family;
    if (ips == AF_INET || ips == AF_INET6)
    {
      printf("%s\t", address->ifa_name);
      printf("%s\t", ips == AF_INET ? "IPV4" : "IPV6");
      char ip[100];
      const int ips_size = ips == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
      getnameinfo(address->ifa_addr, ips_size, ip, sizeof(ip), 0, 0, NI_NUMERICHOST);
      printf("\t%s\n", ip);
    }
    address = address->ifa_next;
  }
  freeifaddrs(addresses);
  return 0;
}
