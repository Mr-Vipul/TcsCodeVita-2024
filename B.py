import heapq

def solve_desert_queen(N, grid):
    
    start, end = None, None
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 'S':
                start = (i, j)
            elif grid[i][j] == 'E':
                end = (i, j)
    
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    

    pq = [(0, start[0], start[1])]
    

    distances = {start: 0}
    visited = set()
    
    while pq:
        water, x, y = heapq.heappop(pq)
        
      
        if (x, y) == end:
            return water
        
        
        if (x, y) in visited:
            continue
        visited.add((x, y))
        
    
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            
          
            if (0 <= nx < N and 0 <= ny < N and 
                grid[nx][ny] != 'M'):
                
              
                if grid[x][y] == 'T' and grid[nx][ny] == 'T':
                    new_water = water
                else:
                    new_water = water + 1
                
              
                if (nx, ny) not in distances or new_water < distances[(nx, ny)]:
                    distances[(nx, ny)] = new_water
                    heapq.heappush(pq, (new_water, nx, ny))
    
    return -1  
N = int(input())
grid = []
for _ in range(N):
    grid.append(input().split())
result = solve_desert_queen(N, grid)
print(result, end ="")