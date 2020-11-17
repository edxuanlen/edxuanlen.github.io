for dir in `ls .`
    do
        if [ -d $dir ]
        then
            echo $dir
            cd $dir
            git config user.email=edxuanlen@gmail.com
            git config user.name=edxuanlen
            cd ..
        fi
    done 