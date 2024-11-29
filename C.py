from collections import deque, defaultdict

def calculate_value_of_string(n, edges, query_string):
    # Step 1: Build the graph
    graph = defaultdict(list)
    in_degree = defaultdict(int)
    all_words = set()
    
    # Read the edges and build the graph
    for word1, word2 in edges:
        graph[word1].append(word2)
        in_degree[word2] += 1
        all_words.add(word1)
        all_words.add(word2)
    
    # Step 2: Find the level of each word using BFS or DFS
    levels = {}
    queue = deque()
    
    # Add all words with no incoming edges (root nodes)
    for word in all_words:
        if in_degree[word] == 0:
            queue.append(word)
            levels[word] = 1  # Root level is 1
    
    # BFS to compute the levels
    while queue:
        current = queue.popleft()
        current_level = levels[current]
        
        for neighbor in graph[current]:
            if neighbor not in levels:  # If the neighbor has not been visited
                levels[neighbor] = current_level + 1
                queue.append(neighbor)
    
    # Step 3: Calculate the value of the query string
    total_value = 0
    for word in query_string:
        if word in levels:
            total_value += levels[word]
        else:
            total_value += -1  # If the word is not in the hierarchy
    
    return total_value

# Step 4: Input handling
def main():
    N = int(input())  # Number of edges
    edges = []
    
    for _ in range(N):
        word1, word2 = input().split()
        edges.append((word1, word2))
    
    query_string = input().split()
    
    result = calculate_value_of_string(N, edges, query_string)
    print(result, end="")  # Ensure no extra newline or space after the result

# Call main function to execute
if __name__ == "__main__":
    main()
