#!/usr/bin/env bash
# Exp 5: case Structure and break
calc() {
    case "$2" in
        +) echo "$1 + $3 = $(($1 + $3))" ;;
        -) echo "$1 - $3 = $(($1 - $3))" ;;
        '*') echo "$1 * $3 = $(($1 * $3))" ;;
        /) echo "$1 / $3 = $(($1 / $3))" ;;
        *) echo "Invalid operator" ;;
    esac
}
calc 20 + 5

day=3
case $day in
    1) echo "Monday" ;; 2) echo "Tuesday" ;; 3) echo "Wednesday" ;;
    4) echo "Thursday" ;; 5) echo "Friday" ;; 6) echo "Saturday" ;; 7) echo "Sunday" ;;
esac

echo "First 4 months with 31 days:"
count=0
for m in Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec; do
    case $m in
        Jan|Mar|May|Jul|Aug|Oct|Dec)
            echo "  $m"
            ((count++))
            if (( count == 4 )); then break; fi
            ;;
    esac
done
