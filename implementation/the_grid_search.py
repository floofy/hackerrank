'''
https://www.hackerrank.com/challenges/the-grid-search
From raw_input, it returns a list of the matrix, the numbers of rows and columns,
returned in a list
'''
def getMatrix():
    tmp = raw_input()               # Input: Row Col
    rows = int(tmp.split()[0])
    cols = int(tmp.split()[1])
    matrix = []
    for row in range(rows):
        matrix.append(raw_input())
    return [matrix, rows, cols]

grid = []
pattern = []

t = int(raw_input())
while t > 0:
    pattern_found = False
    exit_pattern_search = False
    
    tmp = getMatrix()
    grid = tmp[0]           # matrix in list
    g_rows = tmp[1]
    g_cols = tmp[2]
    
    tmp = getMatrix()
    pattern = tmp[0]        # matrix in list
    p_rows = tmp[1]
    p_cols = tmp[2]

    for g_row in range(g_rows):          # parse through entire grid
        if g_row + p_rows > g_rows:     # break if pattern extends past rows in grid  
            break
        for g_col in range(g_cols):
            if g_col+p_cols > g_cols:   # break if pattern col length goes past grid bounds
                break
            if (grid[g_row][g_col] == pattern[0][0]):   # parse through pattern and compare to grid
                for p_row in range(p_rows):
                    for p_col in range(p_cols):
                        if grid[g_row+p_row][g_col+p_col] != pattern[p_row][p_col]:
                            exit_pattern_search = True
                            break
                    if exit_pattern_search:
                        break
                    elif p_row == p_rows-1:
                        pattern_found = True
                        
            exit_pattern_search = False
            
        if pattern_found:
            print "YES"
            break
    
    if not pattern_found:
        print "NO"
        
    t -= 1
