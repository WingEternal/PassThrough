#include <exception>
#include <string>
#include <vector>

namespace PassThrough
{
    class UnitCoder
    {
    private:
        
    public:
        // Encode to Little-Endian
        template<typename T> static bool
        EncodeLE(const T& raw, std::string& data)
        {
            data.clear();

            std::vector<uint8_t> vec(sizeof(T), 0);
            char* ch = reinterpret_cast<char*>(&vec[0]);
            memcpy(ch, &raw, sizeof(T));
            data.assign(vec.begin(), vec.end());

            return true;
        }

        // Encode to Big-Endian
        template<typename T> static bool
        DecodeLE(const char* raw, T& data)
        {
            try
            {
                memcpy(&data, raw, sizeof(T));
            }
            catch(std::exception& e)
            {
                ROS_ERROR_STREAM(e.what());
                return false;
            }
            return true;
        }

        UnitCoder(){};
        ~UnitCoder(){};
    };
    
    

    

} // namespace PassThrough
