# Exp 5: Rootkit Concepts & Defensive Detection Study
- **Definition**: Rootkits attempt to conceal unauthorized processes, files, or kernel modules.
- **Defensive Detection Tools (Linux)**:
  - `sudo chkrootkit` — checks system binaries and LKM signatures.
  - `sudo rkhunter --check` — compares file hashes, hidden files, and suspicious strings.
  - File Integrity Monitoring (FIM) with `AIDE` or `Tripwire`.
