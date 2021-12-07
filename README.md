# PassThrough
* This project is used to encode and decode the transparent data.
* I am often asked to deal with this kind of data, so I built this library in order to avoid duplication of work;)
* This branch is based on C++11.
## Usage
* Include header files in hpp.
* Inherit a new class from PassThrough::ProtocolBase
* Override the following Method:  
`bool toString(std::string& send\_data) const`, which is used to encode message  
&&  
`bool fromString(const std::string& raw_data)`, which is used to decode message
* `unit_template.h` contains methods to encode / decode basic data type.

