# Exp 6: ARP Protocol Analysis, Spoofing Risks & Defenses
- **How ARP Works**: Resolves IPv4 addresses to 48-bit MAC addresses on a LAN via broadcast requests.
- **Detection in Wireshark**: Filter `arp.duplicate-address-detected` or monitor with `arpwatch`.
- **Defenses**: Dynamic ARP Inspection (DAI) on managed switches, static ARP entries (`ip neigh replace ... nud permanent`), and encrypting traffic with TLS/SSH.
