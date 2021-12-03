// Helper code for LC-278
public class VersionControl
{
    private int bad;

    public VersionControl(int bad)
    {
        this.bad = bad;
    }

    boolean isBadVersion(int version)
    {
        return version == bad;
    }
}
