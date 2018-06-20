cd include/json
DELS=$(echo *)
cd ..
rm -rf $DELS

#this file will be used when make copy_h.
#this file must be strange,but I can't find a better way to delete the .h files in json.If I don't delete them from include,there will be some errors.Maybe it's because of conflicts of the .h files.
#this still work well.If you have a better way to make it,just modify this file and the makefile.
