# Exp 7: Intrusion Detection System (Snort IDS) Rules
Example custom rule in `/etc/snort/rules/local.rules`:
```snort
alert icmp any any -> $HOME_NET any (msg:"ICMP Ping Detected"; sid:1000001; rev:1;)
alert tcp any any -> $HOME_NET 80 (msg:"HTTP GET Request Observed"; content:"GET"; sid:1000002; rev:1;)
```
Run in IDS console mode:
```bash
sudo snort -A console -q -c /etc/snort/snort.conf -i eth0
```
