class Term {
    float coef;  // Coefficient
    int expn;    // Exponent

    public Term(float coef, int expn) {
        this.coef = coef;
        this.expn = expn;
    }
}

class Node {
    Term data;
    Node next;

    public Node(Term data) {
        this.data = data;
        this.next = null;
    }
}

class Polynomial {
    Node head;  // Dummy head node

    public Polynomial() {
        head = new Node(new Term(0, 0));
    }

    // Function to compare exponents
    int cmp(int expn1, int expn2) {
        return Integer.compare(expn1, expn2);
    }

    // Function to add two polynomials
    void addPolyn(Polynomial Pb) {
        Node ha = this.head, hb = Pb.head;
        Node qa = ha.next, qb = hb.next;

        while (qa != null && qb != null) {
            Term a = qa.data, b = qb.data;
            switch (cmp(a.expn, b.expn)) {
                case -1:  // Current exponent of qa is smaller than qb's
                    ha = qa;
                    qa = ha.next;
                    break;
                case 0:   // Same exponent, add coefficients
                    qa.data.coef = a.coef + b.coef;
                    if (qa.data.coef != 0) {
                        ha = qa;
                    } else {
                        ha.next = qa.next;
                    }
                    hb.next = qb.next;
                    qa = ha.next;
                    qb = hb.next;
                    break;
                case 1:   // Current exponent of qa is larger than qb's
                    hb.next = qb.next;
                    qb.next = qa;
                    ha.next = qb;
                    qb = hb.next;
                    break;
            }
        }
        if (qb != null) ha.next = qb;  // Append the remaining part of Pb if any
    }

    // Helper function to add a new term to the polynomial
    void addTerm(float coef, int expn) {
        Node newNode = new Node(new Term(coef, expn));
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    // Function to print the polynomial
    void printPolynomial() {
        Node current = head.next;  // Skip the head node
        while (current != null) {
            System.out.print(current.data.coef + "x^" + current.data.expn + " ");
            if (current.next != null) System.out.print("+ ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create two example polynomials for addition
        Polynomial Pa = new Polynomial();
        Pa.addTerm(3.0f, 3);
        Pa.addTerm(2.0f, 2);

        Polynomial Pb = new Polynomial();
        Pb.addTerm(1.0f, 3);
        Pb.addTerm(4.0f, 0);

        System.out.print("Pa: ");
        Pa.printPolynomial();
        System.out.print("Pb: ");
        Pb.printPolynomial();

        Pa.addPolyn(Pb);

        System.out.print("After addition, Pa: ");
        Pa.printPolynomial();
    }
}
