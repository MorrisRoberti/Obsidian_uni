public class StringSet {

    private String container[];

    public StringSet() {
        this.container = new String[0];
    }

    public void add(String x) {
        if (!contains(x)) {
            String[] newContainer = new String[this.container.length + 1];
            for (int i = 0; i < this.container.length; i++) {
                newContainer[i] = this.container[i];
            }

            newContainer[this.container.length] = x;
            this.container = newContainer;
        }
    }

    public boolean contains(String elem) {
        for (int i = 0; i < this.container.length; i++) {
            if (this.container[i].equals(elem))
                return true;
        }
        return false;
    }

    public int size() {
        return this.container.length;
    }

    public boolean isSubsetOf(StringSet other) {
        if (other.container.length > this.container.length)
            return false;
        for (int i = 0; i < other.container.length; i++)
            if (!this.contains(other.container[i]))
                return false;

        return true;
    }

    public StringSet intersect(StringSet other) {
        StringSet result = new StringSet();

        for (int i = 0; i < this.container.length; i++) {
            if (other.contains(this.container[i]))
                result.container[i] = this.container[i];
        }
        return result;
    }

    public StringSet union(StringSet other) {
        StringSet result = new StringSet();

        for (int i = 0; i < this.container.length; i++) {
            result.add(this.container[i]);
        }

        for (int i = 0; i < other.container.length; i++) {
            result.add(this.container[i]);
        }

        return result;
    }

}
