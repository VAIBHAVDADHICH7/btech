# Structured Design (Structure Chart)

```
                 [Library Main Controller]
               /       |           |       \
    [Auth Module] [Catalog Mgr] [Circulation] [Report Gen]
                   /      \       /      \
               [Add]   [Search] [Issue] [Return/Fine]
```

## Module Cohesion & Coupling
- **Cohesion**: Functional cohesion per module (each module performs one well-defined task).
- **Coupling**: Data coupling via explicit DTO parameters (`isbn`, `memberId`).
