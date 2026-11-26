# Exp 4: Observing TCP/UDP Datagrams with Wireshark & tcpdump
```bash
# Capture TCP & UDP traffic on loopback port 8080/8082
sudo tcpdump -i lo -nn -vv '(tcp port 8080) or (udp port 8082)' -w lab_capture.pcap
```
- **Wireshark Display Filters**: `tcp.port == 8080` (inspect 3-way handshake SYN, SYN-ACK, ACK) and `udp.port == 8082` (inspect 8-byte UDP header).
