def distance(a, b):
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2

def polygons(a, b):
    n = len(a)
    if n != len(b):
        return False

    dist_a = []
    dist_b = []
    for i in range(n):
        dist_a.append(distance(a[i], a[(i + 1) % n]))
        dist_b.append(distance(b[i], b[(i + 1) % n]))

    for shift in range(n):
        match = True
        for i in range(n):
            if dist_a[i] != dist_b[(i + shift) % n]:
                match = False
                break
        if match:
            return True

    return False

def main():
    N = int(input())
    earrings = []
    
    for _ in range(N):
        K = int(input())  
        points = [tuple(map(int, input().split())) for _ in range(K)]
        earrings.append(points)

    for i in range(N):
        for j in range(i + 1, N):
            if polygons(earrings[i], earrings[j]):
                print(i + 1, j + 1, end="")
                return

if __name__ == "__main__":
    main()
