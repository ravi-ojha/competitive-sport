inpt = raw_input()
withdraw, initial = [float(i) for i in inpt.split(' ')]
#print withdraw, initial
if float(initial) - float(withdraw)>0 and float(withdraw)%5==0: 
    final = float(withdraw) + 0.50
    print float(initial)-final
else:
    print initial
