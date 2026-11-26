# Exp 10: Merge Sort, Selection Sort, and Insertion Sort
def merge_sort(arr):
    if len(arr) <= 1: return arr
    mid = len(arr) // 2
    L, R = merge_sort(arr[:mid]), merge_sort(arr[mid:])
    res = []; i = j = 0
    while i < len(L) and j < len(R):
        if L[i] <= R[j]: res.append(L[i]); i += 1
        else: res.append(R[j]); j += 1
    return res + L[i:] + R[j:]

def selection_sort(a):
    a = list(a)
    for i in range(len(a)):
        m = min(range(i, len(a)), key=lambda k: a[k])
        a[i], a[m] = a[m], a[i]
    return a

def insertion_sort(a):
    a = list(a)
    for i in range(1, len(a)):
        key, j = a[i], i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]; j -= 1
        a[j + 1] = key
    return a

sample = [38, 27, 43, 3, 9, 82, 10]
print("Merge Sort    :", merge_sort(sample))
print("Selection Sort:", selection_sort(sample))
print("Insertion Sort:", insertion_sort(sample))
