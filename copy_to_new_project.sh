# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    copy_to_new_project.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 16:09:56 by jkauppi           #+#    #+#              #
#    Updated: 2021/11/03 16:35:56 by jkauppi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This sctipr copy all files (excluding git realted files and folders) into
# a folder which is specified in $1 param
#
# Example:
#   bash copy_to_new_project.sh ~/Multilayer-Perceptron/C/lib

SOURCE_FOLDER=$(basename $(realpath .))
TARGET_PATH=$1/$SOURCE_FOLDER
mkdir $TARGET_PATH
cp -r * $TARGET_PATH/
rm $TARGET_PATH/author
echo "Target path: $TARGET_PATH"
