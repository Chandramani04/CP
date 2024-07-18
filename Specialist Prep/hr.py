def sortInRange(L, r):
  
  n = len(L)
  count = [0] * r

  for i in L:
    count[i] += 1
  
  sorted_l = []
  for i in range(r):
    sorted_l.append([i] * count[i])
#   print(sorted_l)
  sortedTemp = []
  for x in sorted_l:
    sortedTemp += x

  print(sortedTemp)
#   return this sortedTemp 

L = [2, 0, 1, 1, 2, 3, 0, 2, 1, 0, 2, 3, 1, 2]
r = 4

ans = sortInRange(L, r)
# print(ans)