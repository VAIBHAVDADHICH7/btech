# Exp 7: Bayesian Network Inference for Heart Disease Diagnosis
# Graph: HighBP -> HeartDisease <- HighCholesterol; HeartDisease -> ChestPain
P_HBP = {True: 0.30, False: 0.70}
P_HChol = {True: 0.25, False: 0.75}
P_HD_given_parents = {
    (True, True): 0.85, (True, False): 0.55,
    (False, True): 0.45, (False, False): 0.10,
}
P_CP_given_HD = {True: 0.80, False: 0.15}

def prob_heart_disease(hbp=True, hchol=True, chest_pain=True):
    p_hd = P_HD_given_parents[(hbp, hchol)]
    num = p_hd * (P_CP_given_HD[True] if chest_pain else 1 - P_CP_given_HD[True])
    den = num + (1 - p_hd) * (P_CP_given_HD[False] if chest_pain else 1 - P_CP_given_HD[False])
    return num / den

print(f"P(HeartDisease | HighBP=True, HighChol=True, ChestPain=True) = {prob_heart_disease(True, True, True):.4f}")
print(f"P(HeartDisease | HighBP=False, HighChol=False, ChestPain=False) = {prob_heart_disease(False, False, False):.4f}")
