import java.util.Scanner;

class Sqlist {
    private static final int MAX_SIZE = 50; // Define maximum size of the list
    private int[] sqlist; // Array to store list elements
    private int size; // Current number of elements in the list

    // Constructor to initialize the list
    public Sqlist() {
        sqlist = new int[MAX_SIZE];
        size = 0;
    }

    // Set the list as empty
    public void setNull() {
        size = 0;
    }

    // Get the length of the list
    public int length() {
        return size;
    }

    // Get element at index i
    public void get(int i) {
        if (i < 1 || i > size) {
            System.out.println("Index out of bounds");
        } else {
            System.out.println("Element at index " + i + " is: " + sqlist[i - 1]);
        }
    }

    // Locate the first occurrence of an element x
    public void locate(int x) {
        int i = 0;
        while (i < size && sqlist[i] != x) {
            i++;
        }
        if (i == size) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element found at index: " + (i + 1));
        }
    }

    // Insert element x at position i
    public void insert(int i, int x) {
        if (i < 1 || i > size + 1) {
            System.out.println("Invalid position, cannot insert");
        } else {
            for (int j = size; j >= i; j--) {
                sqlist[j] = sqlist[j - 1];
            }
            sqlist[i - 1] = x;
            size++;
            display();
        }
    }

    // Delete element at position i
    public void delete(int i) {
        if (i < 1 || i > size) {
            System.out.println("Index out of bounds");
        } else {
            for (int j = i - 1; j < size - 1; j++) {
                sqlist[j] = sqlist[j + 1];
            }
            size--;
            System.out.print("List after deletion: ");
            display();
        }
    }

    // Perform insertion sort on the list
    public void insertSort() {
        for (int i = 1; i < size; i++) {
            int key = sqlist[i];
            int j = i - 1;
            while (j >= 0 && sqlist[j] > key) {
                sqlist[j + 1] = sqlist[j];
                j--;
            }
            sqlist[j + 1] = key;
        }
        System.out.print("Sorted list: ");
        display();
    }

    // Display the list
    public void display() {
        if (size == 0) {
            System.out.println("The list is empty");
        } else {
            for (int j = 0; j < size; j++) {
                System.out.print(sqlist[j] + (j < size - 1 ? " -> " : ""));
            }
            System.out.println();
        }
    }

    // Main function to test the Sqlist class
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Sqlist list = new Sqlist();

        System.out.println("Enter 4 initial elements:");
        for (int i = 0; i < 4; i++) {
            list.insert(i + 1, scanner.nextInt());
        }

        int choice;
        do {
            System.out.println("\nMenu:");
            System.out.println("1: Clear the list");
            System.out.println("2: Display the length");
            System.out.println("3: Get an element by index");
            System.out.println("4: Locate an element");
            System.out.println("5: Insert an element");
            System.out.println("6: Delete an element");
            System.out.println("7: Sort the list");
            System.out.println("8: Display the list");
            System.out.println("0: Exit");
            System.out.print("Choose an option (0-8): ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    list.setNull();
                    System.out.println("List cleared.");
                    break;
                case 2:
                    System.out.println("Length of the list: " + list.length());
                    break;
                case 3:
                    System.out.print("Enter index to retrieve: ");
                    int index = scanner.nextInt();
                    list.get(index);
                    break;
                case 4:
                    System.out.print("Enter element to locate: ");
                    int element = scanner.nextInt();
                    list.locate(element);
                    break;
                case 5:
                    System.out.print("Enter position and element to insert (position, element): ");
                    int pos = scanner.nextInt();
                    int elem = scanner.nextInt();
                    list.insert(pos, elem);
                    break;
                case 6:
                    System.out.print("Enter position to delete: ");
                    int delPos = scanner.nextInt();
                    list.delete(delPos);
                    break;
                case 7:
                    list.insertSort();
                    break;
                case 8:
                    System.out.print("Current list: ");
                    list.display();
                    break;
                case 0:
                    System.out.println("Exiting.");
                    break;
                default:
                    System.out.println("Invalid choice. Please choose between 0-8.");
            }
        } while (choice != 0);

        scanner.close();
    }
}
