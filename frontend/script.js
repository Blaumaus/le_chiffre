const format_date = date => {
  const months = ['Jan.', 'Feb.', 'Mar.', 'Apr.', 'May.', 'Jun.', 'Jul.', 'Aug.', 'Sep.', 'Oct.', 'Nov.', 'Dec.']
  date = date.split('T')[0].split('-')

  return `${date[2]} ${months[date[1] - 1]} ${date[0]}`
}

document.addEventListener('DOMContentLoaded', () => {
  const desc = document.querySelector('#description > p')
  const download = document.getElementById('download_btn')

  fetch('https://api.github.com/repos/blaumaus/le_chiffre/releases?per_page=1')
    .then(res => res.json())
    .then(res => {
      const version = res[0]?.tag_name || 'Unknown'
      const date = res[0]?.published_at || 'Unknown'
      const download_url = res[0].assets[0]?.browser_download_url || 'https://github.com/Blaumaus/le_chiffre/releases'
      
      console.log(date)
      desc.textContent = `The latest cheat version is ${version}, it has been updated on ${format_date(date)}`
      download.textContent = 'Direct download'
      download.href = download_url
    })
    .catch(e => console.log(e))
})