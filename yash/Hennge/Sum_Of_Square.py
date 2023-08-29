def test_case(a, current):
    if current == a:
        return []
    terms = int(input())
    nums = input()
    list1 = nums.split()
    result = [0]
    result = sum_of_square(terms, list1, result)
    return result + test_case(a, current + 1)

def sum_of_square(counter, alist, results):
    if counter == 0:
        return results
    else:
        if int(alist[counter - 1]) < 0:
            results[0] += 0
        else:   
            results[0] += int(alist[counter - 1]) ** 2
        return sum_of_square(counter - 1, alist, results)

def print_results(results):
    if not results:
        return
    print(results[0])
    print_results(results[1:])

if __name__ == "__main__":
    case_count = int(input())
    results = test_case(case_count, 0)
    print_results(results)