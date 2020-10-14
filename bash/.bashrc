# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples
[[ $- == *i* ]] || return 
case $- in
	*i*) ;;
	  *) return;;
esac

# Add vim as default editor
export EDITOR=vim
export TERMINAL=urxvt
export BROWSER=firefox
export PROMPT_COMMAND='echo -ne "\033]0;$PWD\007"'

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# set pager
export PAGER=/usr/bin/most

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# Gtk themes 
export GTK2_RC_FILES="$HOME/.gtkrc-2.0"

xhost +local:root > /dev/null 2>&1

complete -cf sudo
complete -cf man

# Shopt
shopt -s autocd
shopt -s cdspell
shopt -s cmdhist
shopt -s dotglob
shopt -s expand_aliases
shopt -s extglob
shopt -s hostcomplete
shopt -s nocaseglob

# Colour chart
#!/bin/bash
#
UPDATES=$(aptitude search "~U" | wc -l)

echo -e "\033[0;36m"

echo ""

echo "   ▀▄   ▄▀  "

echo -e "  ▄█▀███▀█▄  \033[1;31m "$UPDATES"\033[0;36m  Fucks Given"

echo " █▀███████▀█"

echo " ▀ ▀▄▄ ▄▄▀ ▀"

echo ""

echo -e "\033[m"
# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls++'
    alias dir='dir --color=auto'
    alias vdir='vdir --color=auto'
    alias vpn='nordvpn connect'    
    alias work='bash /opt/forticlient-sslvpn/forticlientsslvpn.sh'    
    alias setup='sh /home/hide4/scripts/./feh.sh'
    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
	alias vim='nvim'
	alias wallpaper='feh --bg-scale ~/Pictures/smileypurp.ong'
fi

color_prompt=yes

# Bash Completion
if [ -f /etc/bash_completion ]; then
	    . /etc/bash_completion
fi

# Alias definitions.
if [ -x ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# Function definitions.
if [ -x ~/.bash_functions ]; then
    . ~/.bash_functions
fi

# Prompt definitions.
if [ -x ~/.bash_prompt ]; then
    . ~/.bash_prompt
fi

## MISC ALIASES ##
alias ls='ls++'
alias ll='ls -l --group-directories-first --time-style=+"%d.%m.%Y %H:%M" --color=auto -F'
alias la='ls -la --group-directories-first --time-style=+"%d.%m.%Y %H:%M" --color=auto -F'
alias grep='grep --color=tty -d skip'
alias cp="cp -i"                          # confirm before overwriting something
alias df='df -h'                          # human-readable sizes
alias free='free -m'                      # show sizes in MB
alias vp='vim PKGBUILD'

alias update='sudo apt-get update'
alias install='sudo apt-get install '
alias uninstall='sudo pacman -Rs'
alias search='pacman -Ss'
alias show='pacman -Si'
alias need='pacman -Qi'
alias missing='pacman -Qk'
alias trash='pacman -Qdt'

alias youtube-mp3='youtube-dl --extract-audio --audio-format mp3'
alias speedtest='speedtest-cli'



alias wvdial='sudo wvdial'

# Color man pages
man() {
	env \
		LESS_TERMCAP_mb=$(printf "\e[1;31m") \
		LESS_TERMCAP_md=$(printf "\e[1;31m") \
		LESS_TERMCAP_me=$(printf "\e[0m") \
		LESS_TERMCAP_se=$(printf "\e[0m") \
		LESS_TERMCAP_so=$(printf "\e[1;44;33m") \
		LESS_TERMCAP_ue=$(printf "\e[0m") \
		LESS_TERMCAP_us=$(printf "\e[1;32m") \
			man "$@"
}

## COMPRESSION FUNCTION ##
function compress_() {
   # Credit goes to: Daenyth
   FILE=$1
   shift
   case $FILE in
      *.tar.bz2) tar cjf $FILE $*  ;;
      *.tar.gz)  tar czf $FILE $*  ;;
      *.tgz)     tar czf $FILE $*  ;;
      *.zip)     zip $FILE $*      ;;
      *.rar)     rar $FILE $*      ;;
      *)         echo "Filetype not recognized" ;;
   esac
}

## EXTRACT FUNCTION ##
extract ()
{
  if [ -f $1 ] ; then
    case $1 in
      *.tar.bz2)   tar xjf $1   ;;
      *.tar.gz)    tar xzf $1   ;;
      *.bz2)       bunzip2 $1   ;;
      *.rar)       unrar x $1     ;;
      *.gz)        gunzip $1    ;;
      *.tar)       tar xf $1    ;;
      *.tbz2)      tar xjf $1   ;;
      *.tgz)       tar xzf $1   ;;
      *.zip)       unzip $1     ;;
      *.Z)         uncompress $1;;
      *.7z)        7z x $1      ;;
      *)           echo "'$1' cannot be extracted via extract()" ;;
    esac
  else
    echo "'$1' is not a valid file"
  fi
}

# test if a file should be opened normally, or as root (edit)
argc () {
        count=0;
        for arg in "$@"; do
                if [[ ! "$arg" =~ '-' ]]; then count=$(($count+1)); fi;
        done;
        echo $count;
}

edit () { if [[ `argc "$@"` > 1 ]]; then vim $@;
                elif [ $1 = '' ]; then vim;
                elif [ ! -f $1 ] || [ -w $1 ]; then vim $@;
                else
                        echo -n "File is Read-only. Edit as root? (Y/n): "
                        read -n 1 yn; echo;
                        if [ "$yn" = 'n' ] || [ "$yn" = 'N' ];
                            then vim $*;
                            else sudo vim $*;
                        fi
                fi
            }

# cd and ls in one
cl() {
    dir=$1
    if [[ -z "$dir" ]]; then
        dir=$HOME
    fi
    if [[ -d "$dir" ]]; then
        cd "$dir"
        ls
    else
        echo "bash: cl: '$dir': Directory not found"
    fi
}

# test encode & decode base64
decode () {
  echo "$1" | base64 -d ; echo
}

encode () {
  echo "$1" | base64 - ; echo
}

# access translate.google.com from terminal
translate () { 
 
# adjust to taste
DEFAULT_TARGET_LANG=en
 
if [[ $1 = -h || $1 = --help ]]
then
    echo "$help"
    exit
fi
 
if [[ $3 ]]; then
    source="$2"
    target="$3"
elif [[ $2 ]]; then
    source=auto
    target="$2"
else
    source=auto
    target="$DEFAULT_TARGET_LANG"
fi
 
echo $i" " $text
result=$(curl -s -i --user-agent "" -d "sl=$source" -d "tl=$target" --data-urlencode "text=$1" http://translate.google.com)
encoding=$(awk '/Content-Type: .* charset=/ {sub(/^.*charset=["'\'']?/,""); sub(/[ "'\''].*$/,""); print}' <<<"$result")
iconv -f $encoding <<<"$result" |  awk 'BEGIN {RS="</div>"};/<span[^>]* id=["'\'']?result_box["'\'']?/' | html2text
}

# prompt
# Needed for git status in the prompt
#source /usr/share/git/git-prompt.sh 


export PS1='\[\e]0;\w\a\]\[\033[31m\][\[\033[0;92m\]\W\[\033[31m\]]\[\033[0;35m\] \[\033[2;33m\]:\[\033[00m\] '

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

# twilio autocomplete setup
TWILIO_AC_BASH_SETUP_PATH=/home/hide4/.twilio-cli/autocomplete/bash_setup && test -f $TWILIO_AC_BASH_SETUP_PATH && source $TWILIO_AC_BASH_SETUP_PATH;
