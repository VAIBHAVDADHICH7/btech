# Exp 3: LAN Installation & Configuration Commands
```bash
# Assign static IP (Linux iproute2)
sudo ip addr add 192.168.10.10/24 dev eth0
sudo ip link set eth0 up
sudo ip route add default via 192.168.10.1

# Verify connectivity & ARP/Routing tables
ping -c 4 192.168.10.1
ip neigh show
ip route show
```
