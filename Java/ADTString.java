class ADTString {
    private char[] ch;
    private int length;

    // Constructor
    public ADTString() {
        this.ch = null;
        this.length = 0;
    }

    // Assigns a new string value to the ADTString
    public void strAssign(String chars) {
        if (chars == null || chars.isEmpty()) {
            this.ch = null;
            this.length = 0;
        } else {
            this.length = chars.length();
            this.ch = chars.toCharArray();
        }
    }

    // Copies the content of another ADTString into this one
    public void strCopy(ADTString source) {
        this.length = source.length;
        this.ch = source.ch.clone();
    }

    // Checks if the string is empty
    public boolean strEmpty() {
        return this.length == 0;
    }

    // Returns the length of the string
    public int strLength() {
        return this.length;
    }

    // Clears the string
    public void clearString() {
        this.ch = null;
        this.length = 0;
    }

    // Concatenates two ADTStrings and returns a new ADTString
    public ADTString concat(ADTString s) {
        ADTString result = new ADTString();
        result.length = this.length + s.length;
        result.ch = new char[result.length];

        System.arraycopy(this.ch, 0, result.ch, 0, this.length);
        System.arraycopy(s.ch, 0, result.ch, this.length, s.length);

        return result;
    }

    // Extracts a substring from start index to end index
    public ADTString subString(int start, int end) {
        if (start < 0 || end > this.length || start >= end) {
            throw new IndexOutOfBoundsException("Invalid substring range");
        }
        ADTString result = new ADTString();
        result.length = end - start;
        result.ch = new char[result.length];
        System.arraycopy(this.ch, start, result.ch, 0, result.length);

        return result;
    }

    // Finds the index of the first occurrence of a character
    public int index(char ch) {
        for (int i = 0; i < this.length; i++) {
            if (this.ch[i] == ch) {
                return i;
            }
        }
        return -1;
    }

    // Replaces all occurrences of a character with another character
    public void replace(char oldChar, char newChar) {
        for (int i = 0; i < this.length; i++) {
            if (this.ch[i] == oldChar) {
                this.ch[i] = newChar;
            }
        }
    }

    // Inserts a character at a specific position
    public void strInsert(char x, int pos) {
        if (pos < 0 || pos > this.length) {
            throw new IndexOutOfBoundsException("Invalid insert position");
        }
        char[] newCh = new char[this.length + 1];
        System.arraycopy(this.ch, 0, newCh, 0, pos);
        newCh[pos] = x;
        System.arraycopy(this.ch, pos, newCh, pos + 1, this.length - pos);
        this.ch = newCh;
        this.length++;
    }

    // Deletes a substring starting from 'pos' with length 'len'
    public void delete(int pos, int len) {
        if (pos < 0 || pos + len > this.length || len < 0) {
            throw new IndexOutOfBoundsException("Invalid delete range");
        }
        char[] newCh = new char[this.length - len];
        System.arraycopy(this.ch, 0, newCh, 0, pos);
        System.arraycopy(this.ch, pos + len, newCh, pos, this.length - pos - len);
        this.ch = newCh;
        this.length -= len;
    }

    // Destroys the string content and resets length
    public void destroy() {
        this.ch = null;
        this.length = 0;
    }

    // Returns the string representation of the ADTString
    @Override
    public String toString() {
        return this.ch == null ? "" : new String(this.ch);
    }
    
    public static void main(String[] args) {
        ADTString str = new ADTString();
        str.strAssign("Hello");
        System.out.println("Assigned String: " + str);

        ADTString copyStr = new ADTString();
        copyStr.strCopy(str);
        System.out.println("Copied String: " + copyStr);

        System.out.println("String Length: " + str.strLength());
        System.out.println("Is String Empty: " + str.strEmpty());

        str.strInsert('!', 5);
        System.out.println("After Insertion: " + str);

        ADTString concatStr = str.concat(new ADTString());
        System.out.println("Concatenated String: " + concatStr);

        System.out.println("Substring (0, 4): " + str.subString(0, 4));

        System.out.println("Index of 'e': " + str.index('e'));

        str.replace('l', 'L');
        System.out.println("After Replace: " + str);

        str.delete(1, 2);
        System.out.println("After Delete: " + str);

        str.destroy();
        System.out.println("After Destroy: " + str);
    }
}
