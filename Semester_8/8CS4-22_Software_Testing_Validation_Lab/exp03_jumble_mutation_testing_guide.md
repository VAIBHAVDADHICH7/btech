# Exp 3: Mutation Score Calculation using Jumble
```bash
# Compile target class and JUnit test class
javac -cp junit-4.13.2.jar:. Exp01e_Calculator.java Exp01e_CalculatorTest.java
# Run Jumble mutation testing
java -jar jumble_binary.jar -c . Exp01e_Calculator
```
**Mutation Score** = `(Killed Mutants / Total Non-Equivalent Mutants) * 100%`
