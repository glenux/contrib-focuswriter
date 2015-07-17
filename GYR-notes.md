Various GLENUX notes
====================

Implementating Reader
---------------------

* use RTFReader as an inspiration (it contains everything needed to change bold, italic, etc.)
* use a markdown library to get the file structure once opened
* read file structure linearly & transform it to RichText instructions


Implementing Writer
--------------------

* No need for a markdown library there (?)
* Read RichText sequencially & transform each style into markdown sequence


Markdown libraries
------------------

* Read: http://stackoverflow.com/questions/889434/markdown-implementations-for-c-c
* Use: https://github.com/cloose/hoedown 


Reference Markdown integration in app
------------------------------------

* https://github.com/cloose/CuteMarkEd
* https://github.com/eduardonunesp/Anomade.git

