char *month(int i)
{
        static char *name[] = {
                "illegal number of month",
                "January", "February", "March",
                "April", "May", "June",
                "July", "August", "September",
                "October", "November", "December"
        };

        return (i < 1 || i > 12) ? name[0] : name[i];
}