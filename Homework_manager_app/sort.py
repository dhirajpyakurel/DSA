from datetime import datetime


def sort_hw(homework: dict):
    for subject, details in homework.items():
        due_date = datetime.strptime(details["due"], "%Y/%m/%d")
        details["date"] = due_date
    
    sorted_subjects = sorted(homework.keys(), key=lambda x: homework[x]["due"], reverse=False)
    
    sorted_hw = {}
    for subject in sorted_subjects:
        due_date = homework[subject]["due"]
        sorted_hw[subject] = {
            "due_date": due_date,
            "description": homework[subject]["description"],
            "completed": homework[subject]["completed"],
            "id": homework[subject]["id"],
            "show": homework[subject]["show"]
        }
    # print(sorted_hw)
    return sorted_hw


def bubble_sort_strings(arr):
    l = len(arr)
    counts = {}
    
    for i in range(l):
        # Last i elements are already sorted
        for j in range(0, l - i - 1):
            # Compare adjacent elements
            if arr[j] > arr[j + 1]:
                # Swap the elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
        
        # Update counts for each element
        for k in range(i, l):
            if arr[k] not in counts:
                counts[arr[k]] = 1
            else:
                counts[arr[k]] += 1
    
    return arr, counts
