/*
Warm up exercise 1
1: Write a function to initialize an array of size 10 with the first 10 positive integers.
2: Given an array and an element, write a function to insert the element at a specified position.
3: Write a function to delete an element from an array at a specified position.
4: Write a function to search for the first occurrence of an element in an array and return its position.
5: Write a function that finds and returns the maximum element in an array.
*/

/*
Pseudo code:
1.
    Function InitializeArray():
        Create an array `arr` of size 10
        For i from 0 to 9:
            arr[i] = i + 1
        Return arr

2. 
    Function InsertElement(arr, element, position):
        If position < 0 or position > length of arr:
            Print "Invalid position"
            Return arr

        Create a new array `newArr` of size length of arr + 1
        For i from 0 to position - 1:
            newArr[i] = arr[i]
        
        newArr[position] = element

        For i from position to length of arr - 1:
            newArr[i + 1] = arr[i]

        Return newArr

3.

Function DeleteElement(arr, position):
    If position < 0 or position >= length of arr:
        Print "Invalid position"
        Return arr

    Create a new array `newArr` of size length of arr - 1
    For i from 0 to position - 1:
        newArr[i] = arr[i]

    For i from position + 1 to length of arr - 1:
        newArr[i - 1] = arr[i]

    Return newArr


4.
Function DeleteElement(arr, position):
    If position < 0 or position >= length of arr:
        Print "Invalid position"
        Return arr

    Create a new array `newArr` of size length of arr - 1
    For i from 0 to position - 1:
        newArr[i] = arr[i]

    For i from position + 1 to length of arr - 1:
        newArr[i - 1] = arr[i]

    Return newArr



*/