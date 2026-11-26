# Data Flow Diagram (DFD) & Data Dictionary

## Level-0 DFD (Context Diagram)
```
[Student/Member] --(Search/Issue Request)--> (( 0.0 Library Management System )) --(Book/Receipt)--> [Student/Member]
[Librarian]      --(Catalog Updates)-------> (( 0.0 Library Management System )) --(Reports)-------> [Librarian]
```

## Level-1 DFD Processes
1. `1.0 Search Catalog` -> Reads `D1: Book_Catalog`
2. `2.0 Issue Book` -> Reads `D1: Book_Catalog`, `D2: Members`; Writes `D3: Transactions`
3. `3.0 Return Book & Compute Fine` -> Updates `D1: Book_Catalog`, `D3: Transactions`
4. `4.0 Generate Reports` -> Reads `D3: Transactions`

## Data Dictionary
- `Book_Record = ISBN + Title + Author + Edition + Status`
- `Member_Record = Member_ID + Name + Department + Max_Quota`
- `Transaction_Record = Txn_ID + ISBN + Member_ID + Issue_Date + Due_Date + Return_Date + Fine`
