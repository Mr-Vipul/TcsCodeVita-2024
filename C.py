from collections import deque, defaultdict

def calculate_value_of_string(n, edges, query_string):
    
    graph = defaultdict(list)
    in_degree = defaultdict(int)
    all_words = set()
    

    for word1, word2 in edges:
        graph[word1].append(word2)
        in_degree[word2] += 1
        all_words.add(word1)
        all_words.add(word2)
    

    levels = {}
    queue = deque()
    
  
    for word in all_words:
        if in_degree[word] == 0:
            queue.append(word)
            levels[word] = 1  
    
    while queue:
        current = queue.popleft()
        current_level = levels[current]
        
        for neighbor in graph[current]:
            if neighbor not in levels:  
                levels[neighbor] = current_level + 1
                queue.append(neighbor)
    
   
    total_value = 0
    for word in query_string:
        if word in levels:
            total_value += levels[word]
        else:
            total_value += -1  
    
    return total_value


def main():
    N = int(input())  
    edges = []
    
    for _ in range(N):
        word1, word2 = input().split()
        edges.append((word1, word2))
    
    query_string = input().split()
    
    result = calculate_value_of_string(N, edges, query_string)
    print(result, end="")  


if __name__ == "__main__":
    main()
