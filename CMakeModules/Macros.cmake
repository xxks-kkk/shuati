# CMake version of spdk_lib_list_to_files defined in spdk.common.mk of SPDK repo
function(write_targets_to_file filename target_list)
    # We convert a list of SPDK lib names to the corresponding file names
    set(ARG_NUM 1)
    while (ARG_NUM LESS ${ARGC})
        set(arg ${ARGV${ARG_NUM}})
        file(WRITE ${filename} "${arg}\n")
        math(EXPR ARG_NUM "${ARG_NUM}+1")
    endwhile()
endfunction(write_targets_to_file)
