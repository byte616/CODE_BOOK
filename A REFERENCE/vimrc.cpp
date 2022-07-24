// vim ~/.vimrc 
// i o a enter -> insert
// <ESC> -> normal -> wq: save and quit
// v -> virtual -> y: crtl+c  p: crtl+v
set nu
set cursorline
set ruler
set linebreak
set showcmd
set scrolloff=5
set hlsearch
set ignorecase
set insearch

syntax on
colorscheme default

set tabstop=4
set expandtab
set shiftwidth=2
set ai
map <Tab> >>
map <S-Tab> <<
set mouse=a
set noswapfile

imap <Enter> o
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap {<CR> {<CR>}<Esc>O
