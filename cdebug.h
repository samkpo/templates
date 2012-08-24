#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

class ShowInfo
{
  /*!
   * \brief Used to show 'logs' in terminal
   * 
   * This class is used to show app outputs in the terminal
   * as log's, debug or errors.
   * 
   * \code
   * ShowInfo(ShowInfo::debug, "main", 5) << "Debugging";
   * \endcode
   * 
   * This would have an output like this:
   * 
   * \code
   * [12:52:23 DEBUG] main:5 Debugging
   * \endcode
   * 
   * In the output you'll see the time of the line execution, the
   * \a type of output you passed, the \a function, the \a line and
   * finally the message
   * 
   * In the case of \a ShowInfo::error and \a ShowInfo::log the output
   * would be
   * 
   * \code
   * [12:52:23  LOG ] message
   * [12:52:23 ERROR] message
   * \endcode
   * 
   * That lines can be simplified using the definitions \n
   * \a DEBUG -> ShowInfo(ShowInfo::debug, __FUNCTION__, __LINE__) \n
   * \a LOG   -> ShowInfo(ShowInfo::log, __FUNCTION__, __LINE__) \n
   * \a ERROR -> ShowInfo(ShowInfo::error, __FUNCTION__, __LINE__)
   * 
   * And Simplify the first example to this:
   * 
   * \code
   * DEBUG << "debugging";
   * LOG << "logging";
   * ERROR << "erroring?";
   * \endcode
   * 
   * In the case that you don't want to use anymore the output of
   * the \a DEBUG command, just and the following preprocesor before
   * the line #include <cdebug>
   * 
   * \code
   * #define NDEBUG
   * #include <cdebug>
   * \endcode
   */
  
  public:
    
    /*!
     * Specifies the type of output to show
     * 
     * \value debug this is showing info as it was an debugging output, only if
     *  DEBUG if defined
     * \value log this will show info as in a logging file
     * \value error this will show info when a error occur
     */
    enum Type{debug, log, error};
    
    /*!
     * Constructor
     * According to \a t, the output will be formatted.
     * if \a t is \a ShowInfo::Debug, then in the output it will
     * show \a funcName, assuming that this is the name of the function
     * where it's called, and if \a line is >= 0, then this will be used
     * as the line number to show.
     */
    ShowInfo(Type t, const std::string &funcName, int line = -1){
      //save var
      _type = t;
      
      //format output
      #ifdef NDEBUG
      if(_type != debug){
        #else
        if(true){
          #endif
          std::cout << "[";
          
          //show current time
          show_time();  //need to make this an stream
          
          //leave an space
          std::cout << " ";
        }
        
        //show data
        switch(_type){
          case debug:
            #ifndef NDEBUG
            std::cout << "DEBUG] " << funcName;
            if(line != -1)
              std::cout  << "::" << line << ": ";
            #endif
              break;
          case log:
            std::cout << " LOG ] ";
            break;
          case error:
            std::cout << "ERROR] ";
            break;
        };  
      };
      
      ~ShowInfo(){
        #ifdef NDEBUG
        if(_type != debug)
          #endif
        std::cout << std::endl;
      };
      
      /*!
       * Whit this operator you send the message that you wanna show.
       */
      template <class T>
      ShowInfo &operator<<(const T &t)
      {
        #ifdef NDEBUG
        if(_type != debug)
          #endif
        std::cout << t;
        return *this;
      };
      
    private:
      Type _type;
      
      /*!
       * this method shows the execution time when is called, formatted
       * as follow:
       * 
       * \code
       * hh:mm:ss
       * \endcode
       * 
       * it doesn't make any line break or something like that.
       */
      void show_time();
    };
    
    #define LOG ShowInfo(ShowInfo::log,__FUNCTION__,__LINE__)
    #define DEBUG ShowInfo(ShowInfo::debug,__FUNCTION__,__LINE__)
    #define ERROR ShowInfo(ShowInfo::error,__FUNCTION__,__LINE__)
    
    #endif // DEBUG_H
    
    //see http://stackoverflow.com/questions/2179623/how-does-qdebug-stuff-add-a-newline-automatically
    //see http://stackoverflow.com/questions/674060/customize-cout
    