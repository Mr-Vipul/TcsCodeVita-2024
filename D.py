def main():
    n = int(input())
    ids = list(map(int, input().split()))
    costs = list(map(int, input().split()))
    budget = int(input())
    
    # Initialize maximum friendliness index (mfi) and maximum friendliness weight (mfw)
    mfi, mfw = 0, 0

    for i in range(n):
        buy_cost = costs[i]
        
        # Check to avoid division by zero
        if buy_cost == 0:
            continue
        
        max_qty = budget // buy_cost
        if max_qty > 0:
            cfi, cfw = 0, 0
            for j in range(n):
                if i != j and ids[i] % ids[j] == 0:
                    cfi += max_qty
                    cfw += costs[j] * max_qty
            
            # Update mfi and mfw if a better combination is found
            if cfi > mfi or (cfi == mfi and cfw > mfw):
                mfi = cfi
                mfw = cfw

    print(mfi, mfw)

if __name__ == "__main__":
    main()
