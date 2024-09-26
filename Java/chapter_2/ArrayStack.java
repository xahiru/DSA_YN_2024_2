
// https://github.com/dinesh-varyani/ds-algos/blob/master/src/com/hubberspot/dsalgo/stack/impl/array/Stack.java
package DSA_YN_2024_2.Java.chapter_2;

public class ArrayStack {

   private int top;
   private int[] arr;

   public ArrayStack(int capacity) {
      top = -1;
      arr = new int[capacity];
   }

   public ArrayStack() {
      this(10);
   }

   public int size() {
      return top + 1;
   }

   public boolean isEmpty() {
      return top < 0;
   }

   public boolean isFull() {
      return arr.length == size();
   }

   public void push(int data) {
      if (isFull()) {
         throw new RuntimeException("Stack is full !!!");
      }
      top++;
      arr[top] = data;
   }

   public int pop() {
      if (isEmpty()) {
         throw new RuntimeException("Stack is empty !!!");
      }
      int result = arr[top];
      top--;
      return result;
   }

   public int peek() {
      if (isEmpty()) {
         throw new RuntimeException("Stack is empty !!!");
      }
      return arr[top];
   }

   public static void main(String[] args) {
      ArrayStack stack = new ArrayStack(3);
      stack.push(10);
      stack.push(15);
      stack.push(20);

      System.out.println(stack.peek());
      stack.pop();
      System.out.println(stack.peek());
      stack.pop();
      System.out.println(stack.peek());
      stack.pop();
      stack.pop();
   }
}