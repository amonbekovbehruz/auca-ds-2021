struct cmpByGpa
{
    bool operator()(cosnt Student &s1, cosnt Student &s2)
    {
        return s1.mGpa > s2.mGpa;
    }
};
