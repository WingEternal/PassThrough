#ifndef PASS_THROUGH_PROTOCOL_TEMPLATE_H
#define PASS_THROUGH_PROTOCOL_TEMPLATE_H

#include <type_traits>

namespace PassThrough
{
    template <typename T> 
    concept IsByte = (std::is_same<char, T>::value 
                       || std::is_same<uint8_t, T>::value);
    template <typename DataPackBase>
    class ProtocolBase
    {
    public:
        // Constructor && Destructor
        ProtocolBase(){};
        virtual ~ProtocolBase(){};
        
        // Decoded Data
        DataPackBase data;

        // basic APIs (must be overrided)
        virtual bool 
        toString(std::string& send_data) const = 0;
        virtual bool
        fromString(const std::string& raw_data) = 0;

        // Extended APIs
        template <IsByte T> bool
        toVector(std::vector<T>& send_data) const
        {
            bool is_success;
            std::string send_str;
            if(is_success = this->toString(send_str))
                send_data.assign(send_str.begin(), send_str.end());
            return is_success;
        }

        template <IsByte T> bool
        fromVector(const std::vector<T>& raw_data)
        {
            std::string raw_str;
            raw_str.assign(raw_data.begin(), raw_data.end());
            return this->fromString(raw_str);
        }

    };
} // namespace PassThrough

#endif