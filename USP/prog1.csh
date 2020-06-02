#!/bin/csh

foreach i($1 $2 $3 $4 $5)
        echo $i 
	echo -n "Entered file Name: "
	set name = $i
	echo $name
	set var1 = `ls -l $name | grep -o ^.`
        set var2 = `echo $var1 | grep -o ^.` 
	if(-e $name) then
		  echo "$name exists"
		  switch($var2)
		         case -:
		              echo "$name is a regular file"
		              breaksw
		         case t:
		              echo "$name is a directory file"
		              breaksw
		         case c:
		              echo "$name is a character device file"
		              breaksw
		         case b:
		              echo "$name is a block device file"
		              breaksw
		         case l:
		              echo "$name is a symbolic link file"
		              breaksw
		         
		         default:
		               echo "file name is unrecognizable"
		               breaksw
		         endsw
	else
		echo "$name does not exist"

	endif    
end                                  
              
