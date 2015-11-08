'''
https://www.hackerrank.com/challenges/matrix-rotation-algo
'''
def convert_matrix(matrix, rings, rows, cols, num_rings):
    for i in range(num_rings):
        h = cols - i*2          # number of horizontal
        v = rows - i*2 - 2      # number of vertical
        start = [i, i]
        ring = []
        matrix = horizontal(matrix, start, h, 'r', True, rings[i])
        matrix = vertical(matrix, [i+1, cols-i-1], v, 'd', True, rings[i][h:])
        matrix = horizontal(matrix, [rows-i-1, cols-i-1], h, 'l', True, rings[i][h+v:])
        matrix = vertical(matrix, [rows-i-2, i], v, 'u', True, rings[i][h+v+h:])
    return matrix

def rotate_rings(rings, R):
    rot_ring = []
    for i in range(len(rings)):
        r2 = R%len(rings[i])
        rot = rings[i][r2:]
        rot += rings[i][0:r2]
        rot_ring.append(rot)
    return rot_ring

def vertical(matrix, start, num_rows, orien, conv = None, rings = None):
    row = start[0]
    col = start[1]
    t = 0
    i = 0
    ver = []
    while t < num_rows:
        if conv == None:
            ver.append(matrix[row+i][col])
        else:
            matrix[row+i][col] = rings[t]
        i += 1 if orien == 'd' else -1
        t += 1
    return ver if conv == None else matrix

def horizontal(matrix, start, num_cols, orien, conv = None, rings = None):
    row = start[0]              # row is static
    col = start[1]              # col is changing
    t = 0
    i = 0
    hor = []
    while t < num_cols:
        if conv == None:
            hor.append(matrix[row][col+i])
        else:
            matrix[row][col+i] = rings[t]
        i += 1 if orien == 'r' else -1
        t += 1
    return hor if conv == None else matrix

def flatten_rings(matrix, rows, cols, num_rings):
    rings = []
    for i in range(num_rings):
        h = cols - i*2          # number of horizontal
        v = rows - i*2 - 2      # number of vertical
        start = [i, i]
        ring = []
        ring += horizontal(matrix, start, h, 'r')
        ring += vertical(matrix, [i+1, cols-i-1], v, 'd')
        ring += horizontal(matrix, [rows-i-1, cols-i-1], h, 'l')
        ring += vertical(matrix, [rows-i-2, i], v, 'u')
        rings.append(ring)
    return rings

if __name__ == "__main__":
    M, N, R = map(int, raw_input().split())
    matrix = []
    for row in range(M):
        matrix.append(raw_input().split())
    num_rings = int(min(M, N)/2)
    rings = flatten_rings(matrix, M, N, num_rings)
    rings = rotate_rings(rings, R)
    matrix = convert_matrix(matrix, rings, M, N, num_rings)
    
    for i in range(M):
        for j in range(N):
            print '{}'.format(matrix[i][j]),
        print
