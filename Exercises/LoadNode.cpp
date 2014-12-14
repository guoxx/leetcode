const int NODE_VERSION_1_2 120
const int NODE_VERSION_1_3 130

class Node
{
public:
    bool Load()
    {
        File reader;
        if (!reader.LoadFile(m_filename))
        {
            return false;
        }

        m_filename = reader.ReadString();
        int version = reader.GetVersion();
        if (!isDeprecated(NODE_VERSION_1_3, version))
        {
            m_priority = reader.ReadInt();
        }
        m_x = reader.ReadFloat();
        m_y = reader.ReadFloat();
        if (isAvailable(NODE_VERSION_1_2, version))
        {
            m_depth = reader.ReadFloat();
        }
        else
        {
            m_depth = 3.5f;
        }
        return true;
    }

private:
    std::string m_filename;
    std::string m_name;
    int     m_priority; // deprecated in version 1.3
    float   m_x;
    float   m_y;
    float   m_depth;    // new to version 1.2 , default value 3.5

    bool isDeprecated(int version, int currentVersion);
    bool isAvailable(int version, int currentVersion);
};

class File
{
public:
    bool LoadFile( const std::string fileName );

    int GetVersion()const;

    const std::string ReadString( );
    float ReadFloat();
    int ReadInt();
}