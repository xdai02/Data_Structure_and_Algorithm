def count(head, foot):
    for chicken in range(head+1):
        rabbit = head - chicken
        if chicken*2 + rabbit*4 == foot:
            print("Chicken: %d, Rabbit: %d" % (chicken, rabbit))

count(35, 94)