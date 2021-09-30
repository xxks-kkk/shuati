class Pair
        implements Comparable<Pair>
{
    Integer key;
    Integer value;

    public Pair(Integer key, Integer value)
    {
        this.key = key;
        this.value = value;
    }

    @Override
    public int compareTo(Pair o)
    {
        return this.key - o.key;
    }
}
