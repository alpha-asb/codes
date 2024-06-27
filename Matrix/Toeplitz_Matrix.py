def isToepliz(mat):
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            if i-1 >-1 and j-1 > -1:
                if mat[i][j] != mat[i-1][j-1]:
                    return False
    return True
